#include <string.h>
#include <ruby.h>
#include <gtk/gtk.h>
#include <rb-gobject-introspection.h>
#include <mate-panel-applet.h>

static gboolean
rb_mpa_factory_callback(MatePanelApplet *applet, const gchar *iid, gpointer user_data)
{
    RBGICallbackData *callback_data = user_data;
    ID id_call;
    
    CONST_ID(id_call, "call");
    VALUE r = rb_funcall(callback_data->rb_callback,
            id_call,
            2,
            GOBJ2RVAL(applet),
            CSTR2RVAL(iid));
    return RVAL2CBOOL(r);
}

static gpointer
rb_mpa_callback_finder(GIArgInfo *info)
{
    GITypeInfo type_info;
    GIBaseInfo *interface_info;
    const gchar *namespace;
    const gchar *name;

    g_arg_info_load_type(info, &type_info);
    interface_info = g_type_info_get_interface(&type_info);
    namespace = g_base_info_get_namespace(interface_info);
    name = g_base_info_get_name(interface_info);

    if (strcmp(namespace, "MatePanelApplet") == 0 && strcmp(name, "AppletFactoryCallback") == 0) {
        return rb_mpa_factory_callback;
    } else {
        return NULL;
    }
}

void
Init_mpa(void)
{
    rb_gi_callback_register_finder(rb_mpa_callback_finder);
}
