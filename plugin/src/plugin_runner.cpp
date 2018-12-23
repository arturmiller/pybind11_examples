#include <thread>
#include <chrono>

#include "plugin_wrapper.cpp"


int main(int argc, char **argv) {
    PluginWrapper plugin("plugin.custom_plugin", "CustomPlugin");

    for(int i=0; i < 10; i++)
    {
        plugin.run();
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }

    return 0;
}

