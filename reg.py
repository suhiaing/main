db={}

global email_exit
email_exit=-1

def main_sector():
    main_option =int(input("Press 1 to Register:\nPress 2 to Login\nPress 3 Exit:"))
    if main_option== 1:
        registration()
    elif main_option==2:
        login()
    elif main_option==3:
        recording_all_data()
        exit(1)
    else:
        print("Invalid Option")
        main_sector()

def registration():

    user_email = input("Enter your email:")
    email_get = Email_exit(user_email)

    if email_get!=None:
        print("Email already exit:")
        registration()
    else:
        user_name = input("Enter your username:")
        user_password = input("Enter your password:")
        user_phone = int(input("Enter your phone:"))
        user_age = int(input("Enter your age:"))

        id = len(db)

        to_insert = {id: {"email": user_email,"u_name":user_name, "password": user_password,"phone":user_phone,"age":user_age}}
        db.update(to_insert)

user_found=-1
def login():
    user_found=-1
    print("This is login sector")
    l_user_email = input("Enter your email to login:")
    l_user_password = input("Enter your password to login:")
    for i in range(len(db)):
        if db[i]["email"] == l_user_email and db[i]["password"]==l_user_password:

            user_found=i
    if user_found!=-1:
        print("Login Success!")
        user_profile(user_found)
    else:
        print("Not Found ")

def user_profile(user_found):
    print("Welcome:",db[user_found]["u_name"])

    option =int(input("Press 1 to exit..Press 2 to update your data.."))
    if option == 1:
        recording_all_data()
        exit(-1)
    elif option == 2:
        print(db[user_found])
        db[user_found].clear()
        user_email = input("Enter your email:")

        user_name = input("Enter your username:")
        user_password = input("Enter your password:")
        user_phone = int(input("Enter your phone:"))
        user_age = int(input("Enter your age:"))

        db[user_found]["email"] = user_email
        db[user_found]["u_name"] = user_name
        db[user_found]["password"] = user_password
        db[user_found]["phone"] = user_phone
        db[user_found]["age"] = user_age
        print(db[user_found])

def Email_exit(email):

    lenght = len(db)
    for i in range(lenght):
        if db[i]["email"] == email:

            return i

def recording_all_data():
    with open("nistdb.txt", 'w') as dbfile:
        for i in range(len(db)):
            email = db[i]["email"]
            user_name = db[i]["u_name"]
            password = db[i]["password"]
            phone = db[i]["phone"]
            age = db[i]["age"]
            total_user_data = email + ' ' + user_name + ' ' + password + ' ' + str(phone) + ' ' + str(age)

            dbfile.write(total_user_data)

def loading_all_data():
    with open("nistdb.txt",'r') as dbfile:
        datas=dbfile.readlines()
        for one in datas:
            oneData = one.split(" ")

            id = len(db)
            data_form = {id:{"email":oneData[0],"u_name":oneData[1],"password":oneData[2],
                             "phone":oneData[3],"age":oneData[4]
                             }}
            db.update(data_form)
        print(db)

def myrecord():
    with open("db.txt", 'a') as f:
        f.write("Hello World")
    

def myLoader():
    with open("db.txt", 'r') as f:
        myData = f.read()
        print("read------------------------------------------------")
        print(myData)
        print(type(myData))
        for i in myData:
            print(i)

if __name__ == '__main__':
    myLoader()
    myrecord()
    # loading_all_data()
    # while True:
    #     main_sector()

