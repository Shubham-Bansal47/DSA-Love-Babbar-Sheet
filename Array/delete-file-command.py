import os
dir_path = r'F:\DSA\LoveBabbarSheet'
file_extenstion = '.exe' # You can change it based on your need. 

for root, _, files in os.walk(dir_path):
    for file in files: 
        if file.endswith(file_extenstion): # for each file in the dir and the sub directories, if the file name ends with the '.exe'
            os.remove(os.path.join(root, file)) # Just delete it