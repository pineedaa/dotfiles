# Carlos Pineda

from .widgets import widget_list

from libqtile.config import Screen
from libqtile import bar

screens = [
    Screen(
        top=bar.Bar(
            widgets=widget_list,
            size=25,
            background="#3b4252.00",
            border_color=["#3b4252.00", "#3b4252.00", "#3b4252.00", "#3b4252.00"],
            border_width=[4, 4, 4, 4],
            opacity=1,
            margin=[4, 8, 0, 8],
        )
    ),
]
