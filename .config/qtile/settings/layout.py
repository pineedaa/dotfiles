# Carlos Pineda

from libqtile import layout

layout_theme = {
        "margin": 5,
        "border_width": 3,
        "border_focus": "#f3f5fb",
        "border_normal": "#3b4252",
    }

layouts = [
    layout.Bsp(margin=6, border_width=3, border_focus="#ebcb8b", border_normal="#3b4252"),
    layout.MonadTall(margin=8, border_width=3, border_focus="#ebcb8b", border_normal="#3b4252"),
    layout.Max(**layout_theme)
]