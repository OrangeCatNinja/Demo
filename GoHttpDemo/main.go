package main

import (
	"fmt"
	"log"
	"net/http"
	"strings"
	"text/template"
)

type User struct {
	Id       int
	Name     string
	Password string
}

var UserById = make(map[int]*User)
var UserByName = make(map[string][]*User)

/*func AuthMiddleWare() gin.HandlerFunc {
	return func(c *gin.Context) {
		token := c.Request.Header.Get("Authorization")
		authorized := check(token)
		if authorized {
			c.Next()
			return
		}
		c.JSON(http.StatusUnauthorized, gin.H{
			"error": "Unauthorized",
		})
		c.Abort()
		return
	}
}*/

func loginMemory(w http.ResponseWriter, r *http.Request) {
	fmt.Println("method: ", r.Method)
	if r.Method == "GET" {
		t, _ := template.ParseFiles("login.tpl")
		log.Println(t.Execute(w, nil))
	} else {
		_ = r.ParseForm()
		fmt.Println("username: ", r.Form["username"])
		fmt.Println("password: ", r.Form["password"])
		user1 := User{1, r.Form.Get("username"), r.Form.Get("password")}
		store(user1)

		if r.Form.Get("password") == "123456" {
			fmt.Fprintf(w, "欢迎登陆,Hello %s", r.Form.Get("username"))
		} else {
			fmt.Println(w, "密码错误，重新输入")
		}
	}
}

func store(user User) {
	UserById[user.Id] = &user
	UserByName[user.Name] = append(UserByName[user.Name], &user)
}

func userInfo(w http.ResponseWriter, r *http.Request) {
	fmt.Println(UserById[1])
	r.ParseForm()
	for _, user := range UserByName[r.Form.Get("username")] {
		fmt.Fprintf(w, "%v", user)
	}
}

func sayHello(w http.ResponseWriter, r *http.Request) {
	_ = r.ParseForm() //解析参数
	fmt.Println(r.Form)
	fmt.Println("Path: ", r.URL.Path)
	fmt.Println("Host: ", r.Host)

	for k, v := range r.Form {
		fmt.Println("key: ", k)
		fmt.Println("val: ", strings.Join(v, ""))
	}
	_, _ = fmt.Fprintf(w, "Hello Web, %s!", r.Form.Get("name"))
}

func main() {
	http.HandleFunc("/", sayHello)
	http.HandleFunc("/login", loginMemory)
	http.HandleFunc("/info", userInfo)
	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
