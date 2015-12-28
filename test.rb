#!/usr/bin/env ruby

require 'gobject-introspection'
require '/home/masm/src/test-ruby-applet/mpa'

require 'gtk3'
Gtk.init

module MatePanelApplet
end
loader = GObjectIntrospection::Loader.new(MatePanelApplet)
loader.load('MatePanelApplet')

ret = MatePanelApplet::Applet.factory_main('TestAppletFactory', true, MatePanelApplet::Applet.gtype) do |applet, iid|
  label = Gtk::Label.new 'Test'
  applet.add label
  applet.show_all
  
  true
end
