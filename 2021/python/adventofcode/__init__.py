from pathlib import Path

__version__ = "2021"


def get_input(day: int) -> list[int]:
    path = Path.cwd().joinpath("..", "inputs", f"day{day}.txt")

    with path.open() as data_file:
        return [int(n) for n in data_file.read().splitlines()]
