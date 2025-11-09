# Food Database (C)

        Simple command-line program in C that stores food items in a binary search tree (sorted by calories), displays items and nutrient totals, prints a basic ASCII nutrient chart for a selected tree node, and appends daily totals to a text file.

        ## Features
        - Add food items (name, calories, carbs, fats, protein, sugar, fiber)
        - Display all food items (in-order by calories)
        - Compute and append daily totals to a file
        - Print a simple ASCII nutrient chart for a selected node
        - Memory freed on exit

        ## Files
        - `main.c` — main source file containing all logic
        - `DailyData.txt` — output file used by default to store daily totals (path controlled inside `fileInput`)

        ## Build
        Requires a C compiler (gcc/clang/MSVC). Example with gcc:
        - On Windows (MinGW/MSYS or WSL):
            - `gcc main.c -o fooddb.exe`
        - On Linux/macOS:
            - `gcc main.c -o fooddb`

        ## Run
        - Run the built executable:
            - `./fooddb` or `fooddb.exe`
        - Use the interactive menu:
            1) Add food item — enter name and numeric nutrient values  
            2) Display all items — lists items sorted by calories  
            3) Save daily totals to file — appends totals with timestamp to `DailyData.txt`  
            4) Display Chart — prints an ASCII bar chart for the root node (or "No data available." when tree is empty)  
            5) Exit

        Example workflow:
        - Add several items (option 1)
        - View sorted list (option 2)
        - Save totals (option 3)
        - View nutrient chart (option 4)
        - Exit (option 5)

        ## Notes & Customization
        - Default file path for daily totals is set in `fileInput()`:
            - `char filePath[]="C:\\Users\\DELL\\Desktop\\DS PBL\\DailyData.txt";`
            - Change this path if you want the file in a different location or make it configurable.
        - The BST uses `calories` as the key; equal-or-greater calories go to the right subtree.
        - The ASCII nutrient chart scales bars to the largest nutrient value (50 characters max).
        - The program uses simple line input helper `readLine()` to safely capture strings.

        ## Troubleshooting
        - If compilation fails, ensure proper function prototypes and include paths; compile with `-Wall -Wextra` to see warnings.
        - On Windows, escape backslashes in paths or use forward slashes as appropriate.
        - If the program can't open the output file, check path permissions and existence of parent directories.

        ## License
        This project is provided as-is. Modify and reuse as needed.
