#include "domain.h"

void Cache::add_endpoint(EndPoint *endpoint, int _latency) {
    endpoints.push_back(endpoint);
    endpoints_id.push_back(endpoint->id);
    latency_to[endpoint] = _latency;
    latency_to_id[endpoint->id] = _latency;
}

void Cache::add_video(Video *video) {
    videos.push_back(video);
    videos_id.push_back(video->id);
    remaining -= video->size;
}

void EndPoint::add_cache(Cache *cache, int _latency) {
    caches.push_back(cache);
    caches_id.push_back(cache->id);
    latency_to[cache] = _latency;
    latency_to_id[cache->id] = _latency;
}

void EndPoint::add_request(Request *request) {
    requests.push_back(request);
    requests_id.push_back(request->id);
}
