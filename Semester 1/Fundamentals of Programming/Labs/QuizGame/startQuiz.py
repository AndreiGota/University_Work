from service.service import Service
from repository.file_repo import FileRepo
from ui.ui import UI

repo = FileRepo()
service = Service(repo)
ui = UI(service)

ui.main_menu()
