#include "global.h"

using namespace std;

/* ============================= */
/* =========== SOLVE =========== */
/* ============================= */

void solve_random() {
    srand(clock());

    for (int cache_id; cache_id < num_caches; ++cache_id) {
        Cache *cache = caches[cache_id];
        vector<Video *> v = videos;
        random_shuffle(v.begin(), v.end());
        for (int i = 0; i < num_videos; ++i) {
            Video *video = v[i];
            if (cache->remaining >= video->size) {
                cache->add_video(video);
            }
        }
    }
}
