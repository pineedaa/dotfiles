# Carlos Pineda

from libqtile import layout
from .colors import colors

layout_theme = {
        'margin': 6,
        'border_width': 3,
        'border_focus': '#f8f8f2',
        'border_normal': '#44475a',
    }

layouts = [
    layout.Bsp(**layout_theme),
    layout.MonadTall(**layout_theme),
    layout.Max(**layout_theme)
]
