from pathlib import Path
from typing import List

from cmake_generator import NewTarget, Target, TargetType

# ----------------------------------------------------------------
def get_target_definitions() -> List[ Target ]:
    shake_core = NewTarget(
        name = 'shake_core',
        target_type = TargetType.SharedLibrary,
        src_dir_path = ( Path( __file__ ).resolve().parent / 'src/' ).as_posix(),
        dependencies = [
            'glm'
        ]
    )
    return [ shake_core ]
