#ifndef __BASE_PLUGIN_H__
#define __BASE_PLUGIN_H__


class BasePlugin{
public:
    BasePlugin();
    virtual void run() = 0;
};


#endif // __BASE_PLUGIN_H__