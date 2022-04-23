# Configuración Qtile Carlos Pineda

import os, numpy, random
import subprocess, json

from settings.keys import mod, keys
from settings.layout import layouts
from settings.screens import screens
from settings.widgets import widget_defaults, extension_defaults

from typing import List  # noqa: F401

from libqtile import hook, qtile, layout
from libqtile.config import Group, Match, Key
from libqtile.lazy import lazy

def changewp():
    wallpapers = os.listdir('/home/carlos/Images/Wallpapers/')
    os.system('feh --bg-fill /home/carlos/Images/Wallpapers/' + wallpapers[random.randint(0, numpy.size(wallpapers) - 1)])

def get_key(name):
    return [k for k, g in grupos.items() if g.name == name][0]

@hook.subscribe.startup_once
def autostart():
    # changewp()
    os.system("feh --bg-fill /hom/carlos/Images/Wallpapers/base.png")
    os.system("lowbattery &")
    os.system("picom &")

grupos = {
        1: Group(""),
        2: Group(" "),
        3: Group(" "),
        4: Group(" "),
        5: Group(" "),
        6: Group(" "),
        7: Group(" ")
        }

groups = [grupos[i] for i in grupos]

for i in groups:
    keys.extend([
        # mod + índice para ir al grupo
        Key([mod], str(get_key(i.name)), lazy.group[i.name].toscreen(),
            desc="Cambiar al grupo {}".format(i.name)),

        # mod + shift + índice del grupo para mover la ventana al grupo e ir
        Key([mod, "shift"], str(get_key(i.name)), lazy.window.togroup(i.name, switch_group=True),
            desc="Mover la ventana e ir al grupo {}".format(i.name))
    ])

dgroups_key_binder = None
dgroups_app_rules = []  # type: List
follow_mouse_focus = True
bring_front_click = False
cursor_warp = False
floating_layout = layout.Floating(float_rules=[
    # Run the utility of `xprop` to see the wm class and name of an X client.
    *layout.Floating.default_float_rules,
    Match(wm_class='confirmreset'),  # gitk
    Match(wm_class='makebranch'),  # gitk
    Match(wm_class='maketag'),  # gitk
    Match(wm_class='ssh-askpass'),  # ssh-askpass
    Match(title='branchdialog'),  # gitk
    Match(title='pinentry'),  # GPG key password entry
], border_focus="#f8f8f2")
auto_fullscreen = True
focus_on_window_activation = "smart"
reconfigure_screens = True

# If things like steam games want to auto-minimize themselves when losing
# focus, should we respect this or not?
auto_minimize = True

# XXX: Gasp! We're lying here. In fact, nobody really uses or cares about this
# string besides java UI toolkits; you can see several discussions on the
# mailing lists, GitHub issues, and other WM documentation that suggest setting
# this string if your java app doesn't work correctly. We may as well just lie
# and say that we're a working one by default.
#
# We choose LG3D to maximize irony: it is a 3D non-reparenting WM written in
# java that happens to be on java's whitelist.
wmname = "LG3D"
