def arithmetics():
    import PySimpleGUI as sg
    import os
    layout = [[sg.Input()],
              [sg.Button('Enter'), sg.Button('Exit')]]
    window = sg.Window('Calculator', layout)
    while True:
        event, values = window.read()
        if event == sg.WINDOW_CLOSED or event == 'Exit':
            break
        if event == 'Enter':
            try:
                result = eval(values[0])
                sg.popup(f"Result: {result}")
            except:
                sg.popup("Invalid input")
    window.close()
    return
