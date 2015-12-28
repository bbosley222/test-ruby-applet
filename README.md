# Sample Applet of MATE Panel in Ruby

## Installation

```
pacman -S gobject-introspection
gem install gobject-introspection
gem install gtk3
```

```
git clone https://github.com/masm11/test-ruby-applet.git
cd test-ruby-applet
```

```
ruby extconf.rb
make
```

```
vi test.rb
```

and edit the 4th line.

```
vi org.mate.panel.applet.TestAppletFactory.service
```

and edit the 3rd line.

```
sudo ln -s /home/masm/src/test-ruby-applet/org.mate.panel.applet.TestAppletFactory.service /usr/share/dbus-1/services/
sudo ln -s /home/masm/src/test-ruby-applet/org.mate.panel.TestApplet.mate-panel-applet /usr/share/mate-panel/applets/
```

## Usage

1. Click the panel with the right button, and select 'Add to Panel'.
2. Select 'Test Applet'.
3. Click the 'Add' button.
