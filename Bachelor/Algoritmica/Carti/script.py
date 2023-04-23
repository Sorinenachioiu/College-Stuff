import pandas as pd 

# define a normalization function
def normalize_string(s):
    s = s.lower()    # convert to lowercase
    s = s.rstrip('s')    # remove trailing 's' characters
    return s

#the excel file that is going to be read
excel_file = 'Xel.xlsx'

subject_count = {}
forbiden_strings = {"Of", "And", "The", "In", "To", "The", "Linear", "Case", "Study:", 
                    "Basic", "Large", "Testing", "World", " Small", "Binary", "Getting", 
                    "Maximum", "On", "WQO", "Value", "And", "Existence", "Strategies", "Nash", 
                    "Theorem", "Limit", "Ruler", "Compass", "Subnormal", "Operators", "Theorems;", 
                    "Free", "Ramsey","study:", "For", "Elementary", "Programming", "Life", "Rare", "Role",
                    "Advanced", "Problem", "knots", "Ant", "Trails", "Sugarscape", "Solving", "criticality",
                    "Complexity", "Colouring", "Planar", "Minors", "Definitions", "Presentations", "Codnitional",
                    "Solvable", "Coxeter", "Law", "Variables","Mixed", "More", "Theory", "Introduction",
                    "Computational", "Topics", "Results", "Sum"}

for currentSheet in range(10):
    # read the excel file, 
    # with the sheet_name in range 1,10 and
    # keep just the column that begins with "Name"
    df = pd.read_excel(excel_file, sheet_name=f"{currentSheet+1}", usecols=['Name'])

    df = df.dropna() # get rid of NaN values 

    # iterate with index and row value using iterrows()
    for index, row in df.iterrows():
        # split each Phrase into words
        words = row['Name'].split()

        # iterate through each word
        for word in words:
            word = normalize_string(word) # normalize the word to better fit the map
            word = word.capitalize() # Make the first letter uppercase
            
            # verify it is a valid word
            if word not in forbiden_strings:
                # if the entry exists
                if word in subject_count:
                    subject_count[word] = subject_count[word] + 1 # increment it
                else:
                    subject_count[word] = 1 # else initialise it
        
# sort subjects by how often they appear
subjects_sorted_by_count = sorted(subject_count.items(), key=lambda x: x[1], reverse=True)
popular_subjects = [] # initialise the result dictionary

# iterate through the dictionary and only keep the subjects that appear more than once
for subject, count in subjects_sorted_by_count:
    if count > 1:
        popular_subjects.append((subject, count))

# create a DataFrame from the subjects_popular list
popular_df = pd.DataFrame(popular_subjects, columns=['Subject', 'Count'])

# write the DataFrame to a new sheet in the same Excel file
with pd.ExcelWriter(excel_file, mode='a') as writer:
    popular_df.to_excel(writer, sheet_name='Popular Subjects', index=False)