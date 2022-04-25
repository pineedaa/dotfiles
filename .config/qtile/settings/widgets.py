# Carlos Pineda

import numpy, os, random
from libqtile import widget, qtile, lazy

widget_defaults = dict(
    font='UbuntuMono Nerd Font',
    fontsize=18,
    padding=0,
    background="#282a36"
)

extension_defaults = widget_defaults.copy()

colors = [
        "#282a36",
        "#44475a",
        "#5a5e77",
        "#717593",
        "#f8f8f2",
        "#000000"
        ]

def transparency(color = "#000000", opacity = 0):
    return color + "." + str(opacity)

def chname(text):
    for string in ["Firefox", "Alacritty", "Thunar", "Spotify", "Code", "MARS", "DrRacket", "@cArchLinux"]:
        if string in text:
            text = string
            if text == "@cArchLinux":
                text = "Alacritty"
        else:
            text = text
    return text

def changewp():
    wallpapers = os.listdir('/home/carlos/Images/Wallpapers/')
    os.system('feh --bg-fill /home/carlos/Images/Wallpapers/' + wallpapers[random.randint(0, numpy.size(wallpapers) - 1)])

def openRandomMenu():
    themes = os.listdir('/home/carlos/.config/rofi/themes')
    theme = themes[random.randint(0, numpy.size(themes) - 1)]
    qtile.cmd_spawn("rofi -show run -theme /home/carlos/.config/rofi/themes/" + theme)

def openMenu():
    qtile.cmd_spawn("rofi -show run")

def onlyMonitor():
    os.system("xrandr --output eDP1 --primary --mode 1920x1080 --pos 0x0 --rotate normal --output DP1 --off --output DP2 --off --output VIRTUAL1 --off")

def openCalendar():
    qtile.cmd_spawn("gsimplecal")

def openNotes():
    qtile.cmd_spawn("alacritty --hold -e utd")

def openHtop():
    qtile.cmd_spawn("alacritty -e gtop")

def open_nm():
    qtile.cmd_spawn("alacritty -e nmtui")

def show_notifies():
    os.system("dunstctl history-pop")

def delete_notifications():
    os.system("dunstctl close-all")

def openbt():
    qtile.cmd_spawn("alacritty -e bluetoothctl")

def openconf():
    qtile.cmd_spawn("alacritty -e code /home/carlos/.config/qtile/")

def openarandr():
    qtile.cmd_spawn("arandr")


widget_defaults = dict(
    font='UbuntuMono Nerd Font',
    fontsize=18,
    padding=0,
    background=colors[1]
)

extension_defaults = widget_defaults.copy()


left = ""
right = ""

widget_list = [
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
        mouse_callbacks={"Button1": openMenu}
    ),
    widget.TextBox(
        text=" ",
        foreground=colors[4],
        background=transparency(colors[2], 8),
        mouse_callbacks={"Button1": openMenu}
    ),
    widget.TextBox(
        text=right,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
        mouse_callbacks={"Button1": openMenu}
    ),        
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
    ),
    widget.GroupBox(
        margin_y=2,
        margin_x=0,
        padding_y=6,
        padding_x=4,
        disable_drag=True,
        use_mouse_wheel=True,
        active=colors[3],
        inactive=colors[0],
        rounded=True,
        highlight_color=colors[4],
        block_highlight_text_color=colors[4],
        highlight_method="text",
        this_current_screen_border=colors[4],
        this_screen_border=colors[2],
        other_current_screen_border=colors[2],
        other_screen_border=colors[2],
        foreground=colors[4],
        background=transparency(colors[2], 8),
        urgent_border=colors[4]
    ),
    widget.TextBox(
        text=right,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
    ),
    widget.Spacer(
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
        mouse_callbacks={"Button1": openCalendar}
    ),
    widget.Clock(
        format=' %H:%M',
        background=transparency(colors[2], 8),
        foreground=colors[4],
        mouse_callbacks={"Button1": openCalendar, "Button3": openNotes}
    ),
    widget.TextBox(
        text=right,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
        mouse_callbacks={"Button1": openCalendar}
    ),
    widget.Spacer(
        background=transparency()
    ),
    widget.TextBox(
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),       text=left,
        mouse_callbacks={'Button1': open_nm, 'Button3': openbt}
    ),
    widget.Wlan(
        foreground=colors[4],
        background=transparency(colors[2], 8),
        format='  {essid}',
        disconnected_message="睊 ",
        mouse_callbacks={'Button1': open_nm, 'Button3': openbt}
    ),
    widget.TextBox(
        font="MesloLGS NF",
        fontsize=26,
        text=right,
        foreground=transparency(colors[2], 8),
        background=transparency(),
        mouse_callbacks={'Button1': open_nm, 'Button3': openbt}
    ),
    widget.Spacer(
        length=24,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
        mouse_callbacks={"Button1": show_notifies, "Button3": delete_notifications}
    ),
    widget.TextBox(
        text=" ",
        foreground=colors[4],
        background=transparency(colors[2], 8),
        mouse_callbacks={"Button1": show_notifies, "Button3": delete_notifications}
    ),
    widget.TextBox(
        text=right,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
        mouse_callbacks={"Button1": show_notifies, "Button3": delete_notifications}
    ),        
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.TextBox(
        font="MesloLGS NF",
        fontsize=26,
        text=left,
        foreground=transparency(colors[2], 8),
        background=transparency(),
    ),
    widget.Battery(
        format="{char} {percent:2.0%}",
        charge_char='',
        discharge_char='',
        empty_char='',
        unknown_char='',
        foreground=colors[4],
        background=transparency(colors[2], 8)
    ),
    widget.TextBox(
        font="MesloLGS NF",
        fontsize=26,
        text=right,
        foreground=transparency(colors[2], 8),
        background=transparency(),
    ),
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
    ),
    widget.TextBox(
        text="墳 ",
        foreground=colors[4],
        background=transparency(colors[2], 8),
    ),
    widget.PulseVolume(
        foreground=colors[4],
        background=transparency(colors[2], 8),
        limit_max_volume=True
    ),
    widget.TextBox(
        text=right,
        font="MesloLGS NF",
        fontsize=26,
        foreground=transparency(colors[2], 8),
        background=transparency(),
    ),        
    widget.Spacer(
        length=12,
        background=transparency()
    ),
]

taskbar=[
    widget.Spacer(
        background=transparency()
    ),
    widget.TextBox(
        font="MesloLGS NF",
        fontsize=26,
        text=left,
        foreground=colors[1],
        background=transparency()
    ),
    widget.TaskList(
        background=colors[1],
        border=colors[3],
        unfocused_border=transparency(colors[2], 6),
        parse_text=chname,
        highlight_method="block",
        txt_floating="  ",
        txt_maximized="  ",
        txt_minimized="  ",
        title_width_method="uniform",
        icon_size=0,
        mouse_callbacks = {"Button2": lambda: qtile.current_window.kill()}
    ),
    widget.TextBox(
        font="MesloLGS NF",
        fontsize=26,
        text=right,
        foreground=colors[1],
        background=transparency()
    ),
    widget.Spacer(
        background=transparency()
    )
]
