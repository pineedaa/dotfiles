# Carlos Pineda

from .widgets import widget_list, taskbar

from libqtile.config import Screen
from libqtile import bar, widget
from libqtile.log_utils import logger

import subprocess

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
        ),
        bottom=bar.Bar(
            widgets=taskbar,
            size=25,
            background="#3b4252.00",
            border_color=["#3b4252.00", "#3b4252.00", "#3b4252.00", "#3b4252.00"],
            border_width=[0, 0, 2, 0],
            opacity=1,
            margin=[4, 8, 0, 8],
        )
    ),
]
