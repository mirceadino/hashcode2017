#include "global.h"

using namespace std;

/* ============================= */
/* =========== SOLVE =========== */
/* ============================= */

const int kMaxVideos = 100005;

vector<pair<double, int>> mlc;
unordered_map<int, int> vid[kMaxVideos];

void solve_alex() {
    srand(time(0));
    for (auto endpoint:endpoints) {
        random_shuffle(endpoint->caches_id.begin(), endpoint->caches_id.end());
    }

    for (auto video:aggregate_videos) {
        int video_id = video.first;
        int cost = video.second;
        int weight = videos[video_id]->size;
        mlc.emplace_back(-1.0 * cost / weight, video_id);
    }

    sort(mlc.begin(), mlc.end());

    for (auto req:requests) {
        vid[req->video_id][req->endpoint_id] += req->count;
    }

    set<pair<int, int>> s;
    for (auto video:mlc) {
        s.clear();
        int video_id = video.second;
        int video_size = videos[video_id]->size;

        for (auto pairr:vid[video_id]) {
            s.insert(make_pair(-pairr.second, pairr.first));
        }

        int curr = 0;
        vector<int> curr_ends;
        while (s.size()) {
            if (curr_ends.size() < endpoints.size() / 10) {
                curr -= s.begin()->first;
                curr_ends.push_back(s.begin()->second);
                s.erase(s.begin());
            } else {
                break;
            }
        }

        set<int> cachess;
        for (auto end:curr_ends) {
            for (int i = 0; i < (int) endpoints[end]->caches_id.size(); i++) {
                int cache_id = endpoints[end]->caches_id[i];
                cachess.insert(cache_id);
                if (cachess.size() > caches.size() / 10) {
                    break;
                }
            }
        }

        for (auto cache:cachess) {
            if (caches[cache]->remaining >= video_size) {
                caches[cache]->add_video(videos[video_id]);
                caches[cache]->remaining -= video_size;
            }
        }
    }
}
