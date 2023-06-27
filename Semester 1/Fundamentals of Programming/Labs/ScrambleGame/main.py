from repository.file_repo import FileRepo
from service.game_service import Service
from service.undo_service import UndoService
from ui.ui import UI

repo = FileRepo()
undo_service = UndoService()
service = Service(repo, undo_service)
ui = UI(service)

ui.play_game()
