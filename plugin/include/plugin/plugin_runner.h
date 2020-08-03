#ifndef __PLUGIN_RUNNER_H__
#define __PLUGIN_RUNNER_H__

#include <list> 

#include <plugin/base_plugin.h>


class PluginRunner{
public:
    PluginRunner();

    void add(BasePlugin* plugin);
    void run();

private:
    std::list<BasePlugin*> plugins;
};


#endif // __PLUGIN_RUNNER_H__