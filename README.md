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

## If you can't get 'Test'.

```
./test.rb
```

and add the applet.

If successful, then check the org.mate.panel.applet.TestAppletFactory file,
otherwise fix the test.rb error.

When it is added by the normal usage, stdout/stderr seem to be closed.
So if you need them, then run it in the command line, and add one.

## Memo

If you use gobject-introspection gem 3.0.7, you need to apply the patch:

https://github.com/ruby-gnome2/ruby-gnome2/commit/2e4dd04021d340f163907435611737e967076aba

If you use gobject-introspection gem >= 3.0.8, you may not need rb-mpa.c.
