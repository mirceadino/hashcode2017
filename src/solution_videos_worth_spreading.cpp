#include "global.h"

using namespace std;

/* ============================= */
/* =========== SOLVE =========== */
/* ============================= */

bitset<100005> mlc;
vector<pair<double, Video *>> sorted_aggregate_videos;

void compute(Cache *cache) {
    unordered_map<int, int> aggregate_videos;
    for (EndPoint *ep: cache->endpoints) {
        for (Request *request: ep->requests) {
            aggregate_videos[request->video_id] += request->count;
        }
    }

    sorted_aggregate_videos.resize(0);
    for (auto x: aggregate_videos) {
        sorted_aggregate_videos.push_back({x.second * 1.0 / videos[x.first]->size, videos[x.first]});
    }
    sort(sorted_aggregate_videos.begin(), sorted_aggregate_videos.end(), greater<pair<double, Video *>>());

    mlc = 0;
    for (EndPoint *ep: cache->endpoints) {
        for (Request *req: ep->requests) {
            mlc[req->video->id] = 1;
        }
    }
}

bool exists(Cache *cache, Video *video) {
    return mlc[video->id];
}

void solve_videos_worth_spreading() {
    for (int cache_id = 0; cache_id < num_caches; ++cache_id) {
        Cache *cache = caches[cache_id];
        compute(cache);
        for (int i = 0; i < sorted_aggregate_videos.size(); ++i) {
            Video *video = sorted_aggregate_videos[i].second;
            if (exists(cache, video) && cache->remaining >= video->size) {
                cache->add_video(video);
            }
        }
    }

    cerr << caches[0]->remaining << endl;
    cerr << caches[0]->videos.size() << endl;
}
