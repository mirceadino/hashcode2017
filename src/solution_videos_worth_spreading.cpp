#include "global.h"

using namespace std;

/* ============================= */
/* =========== SOLVE =========== */
/* ============================= */

void solve_videos_worth_spreading() {
    vector<pair<int, Video *>> sorted_aggregate_videos;
    for (auto x: aggregate_videos) {
        sorted_aggregate_videos.push_back({x.second, videos[x.first]});
    }
    sort(sorted_aggregate_videos.begin(), sorted_aggregate_videos.end(), greater<pair<int, Video *>>());

    for (auto x: sorted_aggregate_videos) {
        cerr << x.first << " id: " << x.second->id << endl;
    }

    int current_remaining = X;
    for (int i = 0; i < sorted_aggregate_videos.size(); ++i) {
        Video *video = sorted_aggregate_videos[i].second;
        if (current_remaining >= video->size) {
            current_remaining -= video->size;
            for (int cache_id = 0; cache_id < num_caches; ++cache_id) {
                Cache *cache = caches[cache_id];
                cache->add_video(video);
            }
        }
    }

    cerr << caches[0]->remaining << endl;
    cerr << caches[0]->videos.size() << endl;
}
