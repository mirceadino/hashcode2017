#ifndef HASHCODE2017_DOMAIN_H
#define HASHCODE2017_DOMAIN_H

#include <bits/stdc++.h>

using namespace std;

class Video;

class Cache;

class EndPoint;

class Request;

class Video {
public:
    Video(int _id) : id(_id), size(0) {}

    Video(int _id, int _size) : id(_id), size(_size) {}

    int id;
    int size;
};


class Cache {
public:
    Cache(int _id) : id(_id), size(0) {}

    Cache(int _id, int _size) : id(_id), size(_size) {}

    void add_endpoint(EndPoint *endpoint, int _latency);

    void add_video(Video *video);

    int id;
    int size;
    vector<EndPoint *> endpoints;
    vector<int> endpoints_id;
    unordered_map<EndPoint *, int> latency_to;
    unordered_map<int, int> latency_to_id;

    vector<Video *> videos;
    vector<int> videos_id;
};

class EndPoint {
public:
    EndPoint(int _id) : id(_id) {}

    void set_dc_latency(int _latency) {
        dc_latency = _latency;
    }

    void add_cache(Cache *cache, int _latency);

    void add_request(Request *request);

    int id;
    int dc_latency;
    vector<Cache *> caches;
    vector<int> caches_id;
    unordered_map<Cache *, int> latency_to;
    unordered_map<int, int> latency_to_id;
    vector<Request *> requests;
    vector<int> requests_id;
};

class Request {
public:
    Request(int _id, Video *_video, EndPoint *_endpoint, int _count) : id(_id), video(_video),
                                                                       endpoint(_endpoint),
                                                                       count(_count) {
        video_id = video->id;
        endpoint_id = endpoint->id;
    }

    int id;
    Video *video;
    int video_id;
    EndPoint *endpoint;
    int endpoint_id;
    int count;
};

#endif //HASHCODE2017_DOMAIN_H