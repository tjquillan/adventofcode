from pathlib import Path
from typing import Callable, TypeVar

__version__ = "2021"

T = TypeVar("T")


def _default_processor(val: str) -> str:
    return val


def get_input(day: int, processor: Callable[[str], T] = _default_processor) -> list[T]:
    path = Path.cwd().joinpath("..", "inputs", f"day{day}.txt")

    with path.open() as data_file:
        return [processor(n) for n in data_file.read().splitlines()]
