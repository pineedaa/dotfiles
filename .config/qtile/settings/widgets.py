# Carlos Pineda

import numpy, os, random
from .theme import colors
from libqtile import widget, qtile

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

def openMenu():
    themes = os.listdir('/home/carlos/.config/rofi/themes')
    theme = themes[random.randint(0, numpy.size(themes) - 1)]
    qtile.cmd_spawn("rofi -show run -theme /home/carlos/.config/rofi/themes/" + theme)

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
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[6],
            background=colors[18],
            mouse_callbacks={"Button1": openMenu}
        ),
        widget.TextBox(
            text=" ",
            foreground=colors[2],
            background=colors[6],
            mouse_callbacks={"Button1": openMenu}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[6],
            background=colors[18],
            mouse_callbacks={"Button1": openMenu}
        ),
        widget.Spacer(
            background=colors[18],
            length=12,
            mouse_callbacks={'Button1' : openconf}
        ),
        widget.TextBox(
            text="",
            background=colors[18],
            mouse_callbacks={'Button1' : openconf}
        ),
        widget.Spacer(
            background=colors[18],
            length=12,
            mouse_callbacks={'Button1' : openconf}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[14],
            background=colors[18]
        ),
        widget.GroupBox(
            margin_y=2,
            margin_x=0,
            padding_y=6,
            padding_x=4,
            disable_drag=True,
            use_mouse_wheel=True,
            active=colors[13],
            inactive=colors[10],
            rounded=True,
            highlight_color=colors[2],
            block_highlight_text_color=colors[6],
            highlight_method="text",
            this_current_screen_border=colors[4],
            this_screen_border=colors[4],
            other_current_screen_border=colors[14],
            other_screen_border=colors[14],
            foreground=colors[1],
            background=colors[14],
            urgent_border=colors[3]
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[14],
            background=colors[18]
        ),
        widget.Spacer(
            background=colors[18],
            length=12
        ),
        #widget.TaskList(),
        widget.TextBox(
            text="",
            background=colors[18]
        ),
        widget.Spacer(
            background=colors[18],
            length=12
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[4],
            background=colors[18],
            mouse_callbacks={"Button1": openHtop}
        ),
        widget.CPU(
            format=" {load_percent}% ",
            foreground=colors[2],
            background=colors[4],
            mouse_callbacks={"Button1": openHtop}
        ),
        widget.TextBox(
            text="◀",
            fontsize=32,
            foreground=colors[3],
            background=colors[4],
            padding=-4,
            mouse_callbacks={"Button1": openHtop}
        ),
        widget.Memory(
            format='  {MemUsed: .0f}{mm}/{MemTotal: .0f}{mm}',
            foreground=colors[2],
            background=colors[3],
            mouse_callbacks={"Button1": openHtop}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[3],
            background=colors[18],
            mouse_callbacks={"Button1": openHtop}
        ),
        widget.Spacer(
            background=colors[18],
            mouse_callbacks={"Button1": changewp}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[15],
            background=colors[18],
            mouse_callbacks={"Button1": openCalendar}
        ),
        widget.Clock(
            format=' %H:%M',
            background=colors[15],
            foreground=colors[2],
            mouse_callbacks={"Button1": openCalendar, "Button3": openNotes}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[15],
            background=colors[18],
            mouse_callbacks={"Button1": openCalendar}
        ),
        widget.Spacer(
            background=colors[18],
            mouse_callbacks={"Button1": changewp}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[6],
            background=colors[18],
            mouse_callbacks={'Button1' : open_nm, 'Button3' : openbt}
        ),
        widget.Wlan(
            foreground=colors[2],
            background=colors[6],
            format='  {essid}',
            disconnected_message="睊 ",
            mouse_callbacks={'Button1' : open_nm, 'Button3' : openbt}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[6],
            background=colors[18],
            mouse_callbacks={'Button1' : open_nm, 'Button3' : openbt}
        ),
        widget.Spacer(
            background=colors[18],
            length=12
        ),
        widget.TextBox(
            text="",
            background=colors[18]
        ),
        widget.Spacer(
            background=colors[18],
            length=12
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[7],
            background=colors[18]
        ),
        widget.Battery(
            format="{char} {percent:2.0%}",
            charge_char='',
            discharge_char='',
            empty_char='',
            unknown_char='',
            foreground=colors[2],
            background=colors[7]
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[7],
            background=colors[18]
        ),
        widget.Spacer(
            background=colors[18],
            length=10
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[8],
            background=colors[18]
        ),
        widget.TextBox(
            text="墳 ",
            foreground=colors[2],
            background=colors[8]
        ),
        widget.PulseVolume(
            emoji=False,
            limit_max_volume=True,
            foreground=colors[2],
            background=colors[8]
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[8],
            background=colors[18]
        ),
        widget.Spacer(
            background=colors[18],
            length=10
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[5],
            background=colors[18],
            mouse_callbacks={'Button1' : show_notifies, 'Button3' : delete_notifications}
        ),
        widget.TextBox(
            text=" ",
            foreground=colors[2],
            background=colors[5],
            mouse_callbacks={'Button1' : show_notifies, 'Button3' : delete_notifications}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[5],
            background=colors[18],
            mouse_callbacks={'Button1' : show_notifies, 'Button3' : delete_notifications}
        ),
        widget.Spacer(
            background=colors[18],
            length=12,
        ),
        widget.TextBox(
            text="",
            background=colors[18]
        ),
        widget.Spacer(
            background=colors[18],
            length=12
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[6],
            background=colors[18],
            mouse_callbacks={'Button1' : openarandr}
        ),
        widget.TextBox(
            text=" ",
            background=colors[6],
            foreground=colors[2],
            mouse_callbacks={'Button1' : openarandr}
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[6],
            background=colors[18],
            mouse_callbacks={'Button1' : openarandr}
        ),
        widget.Spacer(
            background=colors[18],
            length=12
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=left,
            foreground=colors[11],
            background=colors[18]
        ),
        widget.CurrentLayout(
            foreground=colors[2],
            background=colors[11]
        ),
        widget.TextBox(
            font="MesloLGS NF",
            fontsize=26,
            text=right,
            foreground=colors[11],
            background=colors[18]
        )
]

taskbar=[
    widget.Spacer(
        background=colors[18]
    ),
    widget.TextBox(
        font="MesloLGS NF",
        fontsize=26,
        text=left,
        foreground="#3b4252.9",
        background=colors[18]
    ),
    widget.TaskList(
        background="#3b4252.9",
        border="#8ce7ff.3",
        unfocused_border="#5e81ac.2",
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
        foreground="#3b4252.9",
        background=colors[18]
    ),
    widget.Spacer(
        background=colors[18]
    )
]

