# Carlos Pineda

import numpy, os, random
from libqtile import widget, qtile, lazy

from .colors import colors

widget_defaults = dict(
    font='UbuntuMono Nerd Font',
    fontsize=18,
    padding=0,
    background='#282a36'
)
extension_defaults = widget_defaults.copy()

# Función que sirve para asignarle transparencia a un color
def transparency(color = '#000000', opacity = 0):
    return color + '.' + str(opacity)

def transparency_gradient(color = ['#000000', '#ffffff'], opacity = 0):
    return [color[0] + '.' + str(opacity), color[1] + '.' + str(opacity)]

def chname(text):
    for string in ['Firefox', 'Alacritty', 'Thunar', 'Spotify', 'Code', 'MARS', 'DrRacket', '@cArchLinux']:
        if string in text:
            text = string
            if text == '@cArchLinux':
                text = 'Alacritty'
        else:
            text = text
    return text

# Con esta función cambiamos a un fondo de pantalla aleatorio dentro de la carpeta que pongamos
def changewp():
    wallpapers = os.listdir('~/Images/Wallpapers/')
    os.system('feh --bg-fill ~/Images/Wallpapers/' + wallpapers[random.randint(0, numpy.size(wallpapers) - 1)])

# Abre rofi con un tema aleatorio dentro de la carpeta themes de rofi
def openRandomMenu():
    themes = os.listdir('~/.config/rofi/themes')
    theme = themes[random.randint(0, numpy.size(themes) - 1)]
    qtile.cmd_spawn('rofi -show run -theme ~/.config/rofi/themes/' + theme)

# Abre rofi
def openMenu():
    qtile.cmd_spawn('rofi -show run -theme ~/.config/rofi/themes/photon-violet.rasi')

def openCalendar():
    qtile.cmd_spawn('gsimplecal')

# Abre networkmanager en tui
def open_nm():
    qtile.cmd_spawn('alacritty -e nmtui')

# Abre firefox
def openFirefox():
    qtile.cmd_spawn('firefox')

# Abre el gestor de archivos
def openFiles():
    qtile.cmd_spawn('thunar')

# Abre neovim
def openVim():
    qtile.cmd_spawn('alacritty -e nvim')

# Abre code-oss
def openCode():
    qtile.cmd_spawn('code')

# Abre el terminal
def openTerminal():
    qtile.cmd_spawn('alacritty')

# Recupera las notificaciones
def show_notifies():
    os.system('dunstctl history-pop')

# Borra las notificaciones
def delete_notifications():
    os.system('dunstctl close-all')

# Abre el bluetoothctl en cosola
def openbt():
    qtile.cmd_spawn('blueman-manager')

widget_defaults = dict(
    font='UbuntuMono Nerd Font',
    fontsize=18,
    padding=0,
    background=colors[1]
)

extension_defaults = widget_defaults.copy()


left = ''
right = ' '

widget_list = [
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
        mouse_callbacks={'Button1': openMenu}
    ),
    widget.TextBox(
        text=' ',
        foreground=colors[4],
        background=colors[2],
        mouse_callbacks={'Button1': openMenu}
    ),
    widget.TextBox(
        text=right,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
        mouse_callbacks={'Button1': openMenu}
    ),        
    widget.Spacer(
        length=0,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
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
        highlight_method='text',
        this_current_screen_border=colors[4],
        this_screen_border=colors[2],
        other_current_screen_border=colors[2],
        other_screen_border=colors[2],
        foreground=colors[4],
        background=colors[2],
        urgent_border=colors[4]
    ),
    widget.TextBox(
        text=right,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
    ),
    widget.Spacer(
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
        mouse_callbacks={'Button1': openCalendar}
    ),
    widget.Clock(
        format=' %H:%M',
        background=colors[2],
        foreground=colors[4],
        mouse_callbacks={'Button1': openCalendar}
    ),
    widget.TextBox(
        text=right,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
        mouse_callbacks={'Button1': openCalendar}
    ),
    widget.Spacer(
        background=transparency()
    ),
    widget.TextBox(
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),       text=left,
        mouse_callbacks={'Button1': open_nm, 'Button3': openbt}
    ),
    widget.Wlan(
        foreground=colors[4],
        background=colors[2],
        format='  {essid}',
        disconnected_message='睊 ',
        mouse_callbacks={'Button1': open_nm, 'Button3': openbt}
    ),
    widget.TextBox(
        font='MesloLGS NF',
        fontsize=26,
        text=right,
        foreground=colors[2],
        background=transparency(),
        mouse_callbacks={'Button1': open_nm, 'Button3': openbt}
    ),
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
        mouse_callbacks={'Button1': show_notifies, 'Button3': delete_notifications}
    ),
    widget.TextBox(
        text=' ',
        foreground=colors[4],
        background=colors[2],
        mouse_callbacks={'Button1': show_notifies, 'Button3': delete_notifications}
    ),
    widget.TextBox(
        text=right,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
        mouse_callbacks={'Button1': show_notifies, 'Button3': delete_notifications}
    ),        
    widget.Spacer(
        length=0,
        background=transparency()
    ),
    widget.TextBox(
        font='MesloLGS NF',
        fontsize=26,
        text=left,
        foreground=colors[2],
        background=transparency(),
    ),
    widget.Battery(
        format='{char} {percent:2.0%}',
        charge_char='',
        discharge_char='',
        empty_char='',
        unknown_char='',
        foreground=colors[4],
        background=colors[2],
        low_foreground='#FF0000',
        low_percentage=0.2
    ),
    widget.TextBox(
        font='MesloLGS NF',
        fontsize=26,
        text=right,
        foreground=colors[2],
        background=transparency(),
    ),
    widget.Spacer(
        length=0,
        background=transparency()
    ),
    widget.TextBox(
        text=left,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
    ),
    widget.TextBox(
        text='墳 ',
        foreground=colors[4],
        background=colors[2],
    ),
    widget.PulseVolume(
        foreground=colors[4],
        background=colors[2],
        limit_max_volume=True
    ),
    widget.TextBox(
        text=right,
        font='MesloLGS NF',
        fontsize=26,
        foreground=colors[2],
        background=transparency(),
    ),
    widget.Spacer(
        length=0,
        background=transparency()
    ),
]

taskbar=[
    widget.Spacer(
        background=transparency()
    ),
    widget.TextBox(
        font='MesloLGS NF',
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
        highlight_method='block',
        txt_floating='  ',
        txt_maximized='  ',
        txt_minimized='  ',
        title_width_method='uniform',
        icon_size=0,
        mouse_callbacks = {'Button2': lambda: qtile.current_window.kill()}
    ),
    widget.TextBox(
        font='MesloLGS NF',
        fontsize=26,
        text=right,
        foreground=colors[1],
        background=transparency()
    ),
    widget.Spacer(
        background=transparency()
    ),
    widget.Systray(
        background=transparency()
    ),
    widget.Spacer(
        length=12,
        background=transparency()
    )
]

icons = [
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.Image(
        filename='~/.config/qtile/icons/adventures-of-shuggy.svg',
        background=transparency(),
        mouse_callbacks={'Button1': openMenu}
    ),
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.Image(
        filename='~/.config/qtile/icons/firefox-trunk.svg',
        background=transparency(),
        mouse_callbacks={'Button1': openFirefox}
    ),
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.Image(
        filename='~/.config/qtile/icons/system-file-manager.svg',
        background=transparency(),
        mouse_callbacks={'Button1': openFiles}
    ),
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.Image(
        filename='~/.config/qtile/icons/Alacritty.svg',
        background=transparency(),
        mouse_callbacks={'Button1': openTerminal}
    ),
    widget.Spacer(
        length=12,
        background=transparency()
    ),
    widget.Image(
        filename='~/.config/qtile/icons/visual-studio-code.svg',
        background=transparency(),
        mouse_callbacks={'Button1': openCode}
    ),
]
