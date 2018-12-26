#include <thread>
#include <chrono>
#include <list> 
#include <iterator>

#include "plugin_wrapper.cpp"


class PluginRunner{
public:
    PluginRunner() { }
    void add(BasePlugin* plugin)
    {
        plugins.push_back(plugin);
    }

    void run()
    {
        std::list<BasePlugin*>::iterator plugin = plugins.begin();
        while(plugin != plugins.end())
        {
	        (*plugin)->run();
            plugin++;
        }
    }

private:
    std::list<BasePlugin*> plugins;
};


int main(int argc, char **argv) {
    PluginRunner plugin_runner;
    plugin_runner.add(new PluginWrapper("plugin.custom_plugin", "CustomPlugin"));
    plugin_runner.run();

    return 0;
}

