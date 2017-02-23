#include "global.h"

using namespace std;

/* ============================= */
/* =========== SOLVE =========== */
/* ============================= */

const int kMaxDim = 50005;
const int kMaxVideos = 10005;
const int kInf = (1 << 29) - 1;
vector<pair<double, int>> aggregate_videos_knapsack;

void solve_trending_today() {
    srand(time(0));
    for (auto video:aggregate_videos) {
        int video_id = video.first;
        int cost = video.second;
        int weight = videos[video_id]->size;
        aggregate_videos_knapsack.emplace_back(-1.0 * cost / weight, video_id);
    }

    for (int cache = 0; cache < num_caches; cache++) {
        cout << cache << '\n';

        sort(aggregate_videos_knapsack.begin(), aggregate_videos_knapsack.end());

        int current_size = cache_size;
        vector<int> video_indexes;
        for (auto video:aggregate_videos_knapsack) {
            int video_id = video.second;
            int weight = videos[video_id]->size;
            int randum = rand() % 3;
            if (randum == 0) {
                continue;
            }
            if (weight <= current_size) {
                current_size -= weight;
                video_indexes.push_back(video_id);
            }
        }

        unordered_map<int, bool> used;
        for (auto it:video_indexes) {
            caches[cache]->add_video(videos[it]);
            used[it] = 1;
        }

        vector<pair<double, int>> aux;
        for (auto it:aggregate_videos_knapsack) {
            int id = it.second;
            if (used.count(id)) {
                continue;
            }
            aux.push_back(it);
        }
        aggregate_videos_knapsack = aux;
    }
}
