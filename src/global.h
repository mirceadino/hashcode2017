#ifndef HASHCODE2017_GLOBAL_H
#define HASHCODE2017_GLOBAL_H

#include "domain.h"
#include <bits/stdc++.h>

extern int V, E, R, C, X;
extern int num_videos, num_endpoints, num_caches, num_requests, cache_size;
extern vector<Video *> videos;
extern vector<EndPoint *> endpoints;
extern vector<Cache *> caches;
extern vector<Request *> requests;
extern unordered_map<int, int> aggregate_videos;

#endif //HASHCODE2017_GLOBAL_H
