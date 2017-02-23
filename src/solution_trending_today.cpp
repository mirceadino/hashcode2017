#include "global.h"

using namespace std;

/* ============================= */
/* =========== SOLVE =========== */
/* ============================= */

const int kMaxDim = 50005;
const int kMaxVideos = 10005;
const int kInf = (1 << 29) - 1;
int dp[kMaxDim];
int father[kMaxDim];
int last_video[kMaxDim];
pair<int, int> aggregate_videos_knapsack[kMaxVideos];

void solve_trending_today() {
//    for (auto video:aggregate_videos) {
//        aggregate_videos_knapsack[video.first] = video.second;
//    }

    for (int i = 0; i < num_caches; i++) {
        for (int j = 0; j < kMaxDim; j++) {
            dp[j] = -1;
        }
        dp[0] = 0;

        for (auto video:aggregate_videos_knapsack) {
            int video_id = video.first;
            int weight = videos[video_id]->size;
            int cost = video.second;

            for (int i = kMaxDim - 1; i >= weight; i--) {
                if (dp[i - weight] != -1) {
                    dp[i] = max(dp[i], dp[i - weight] + cost);
                    father[i] = i - weight;
                    last_video[i] = video_id;
                }
            }
        }


    }
}
