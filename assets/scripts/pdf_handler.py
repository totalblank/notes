import os, shutil

list_pdfs = []

for root, dirs, files in os.walk('../../'):
    if not (root.startswith('../../assets') and root.startswith('../../pdf_exports')):
        for file in files:
            if os.path.splitext(file)[1] == '.pdf':
                list_pdfs.append(os.path.abspath(os.path.join(root, file)))

list_pdfs = list(set(list_pdfs))

for file in list_pdfs:
    try:
        shutil.copy(file, f'../../pdf_exports/{os.path.split(file)[1]}')
    except (FileNotFoundError, shutil.SameFileError) as error:
        print(error)
