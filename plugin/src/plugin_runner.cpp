#include <iterator>

#include <plugin/plugin_runner.h>
#include <plugin/plugin_wrapper.h>


PluginRunner::PluginRunner() { }

void PluginRunner::add(BasePlugin* plugin)
{
    plugins.push_back(plugin);
}

void PluginRunner::run()
{
    std::list<BasePlugin*>::iterator plugin = plugins.begin();
    while(plugin != plugins.end())
    {
        (*plugin)->run();
        plugin++;
    }
}


int main(int argc, char **argv) {
    PluginRunner plugin_runner;
    plugin_runner.add(new PluginWrapper("plugin.custom_plugin", "CustomPlugin"));
    plugin_runner.run();

    return 0;
}