#include "global.h"

using namespace std;

/* ============================= */
/* ===== GLOBAL VARIABLES ====== */
/* ============================= */

int V, E, R, C, X;
int num_videos, num_endpoints, num_caches, num_requests, cache_size;
vector<Video *> videos;
vector<EndPoint *> endpoints;
vector<Cache *> caches;
vector<Request *> requests;

const int TESTCASE = 0;
const vector<string> testcases = {
        "kittens", "me_at_the_zoo", "trending_today", "videos_worth_spreading"
};
const string input_file = "../" + testcases[TESTCASE] + ".in";
const string output_file = "../" + testcases[TESTCASE] + ".out";

/* ============================= */
/* ======== I/O METHODS ======== */
/* ============================= */

void read() {
    freopen(input_file.c_str(), "r", stdin);

    cin >> V >> E >> R >> C >> X;
    num_videos = V;
    num_endpoints = E;
    num_caches = C;
    num_requests = R;
    cache_size = X;

    // Create caches.
    for (int i = 0; i < C; ++i) {
        caches.push_back(new Cache(i, X));
    }

    // Read videos.
    for (int i = 0, size; i < V; ++i) {
        cin >> size;
        videos.push_back(new Video(i, size));
    }

    // Read endpoints.
    for (int i = 0, dc_latency, num_caches; i < E; ++i) {
        cin >> dc_latency >> num_caches;
        endpoints.push_back(new EndPoint(i));
        EndPoint *endpoint = endpoints.back();

        for (int j = 0, cache_id, latency; j < num_caches; ++j) {
            cin >> cache_id >> latency;
            endpoint->add_cache(caches[cache_id], latency);
            caches[cache_id]->add_endpoint(endpoint, latency);
        }

        endpoint->set_dc_latency(dc_latency);
    }

    // Read requests.
    for (int i = 0, video_id, endpoint_id, count; i < R; ++i) {
        cin >> video_id >> endpoint_id >> count;
        requests.push_back(new Request(i, videos[video_id], endpoints[endpoint_id], count));
        Request *request = requests.back();
        endpoints[endpoint_id]->add_request(request);
    }
}

extern void solve_template();

extern void solve_random();

void print() {
    freopen(output_file.c_str(), "w", stdout);

    cout << num_caches << endl;
    for (int i = 0; i < num_caches; ++i) {
        cout << i << " ";
        for (int video_id: caches[i]->videos_id) {
            cout << video_id << " ";
        }
        cout << endl;
    }
}


/* ============================= */
/* =========== MAIN ============ */
/* ============================= */

int main() {
    read();
    solve_random();
    print();

    return 0;
}