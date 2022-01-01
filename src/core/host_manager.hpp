#pragma once
#include "common.hpp"
#include <set>
using namespace std;

class HostManager {
    public:
        HostManager(json config, string myName="");
        HostManager(); // only used for  mocks
        size_t size();
        void refreshHostList();

        std::pair<string,uint64_t> getRandomHost();
        vector<string> getHosts(bool includeSelf=true);
        set<string> sampleHosts(int count);
        
        void addPeer(string addr);
        bool isDisabled();
    protected:
        bool disabled;
        string myAddress;
        string myName;
        vector<string> hostSources;
        vector<string> hosts;
};

