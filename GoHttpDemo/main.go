package main

import (
	"database/sql"
	"fmt"
	"github.com/gin-gonic/gin"
	"log"
	"net/http"
	"strings"
	"text/template"
	"time"
)

type User struct {
	Id         int
	Name       string
	Password   string
	CreateTime string
}

var UserById = make(map[int]*User)
var UserByName = make(map[string][]*User)
var db, err = sql.Open("mysql",
	"yantian:123456@tcp(127.0.0.1:3306)/user?charset=utf8")

func AuthMiddleWare() gin.HandlerFunc {
	return func(c *gin.Context) {
		/*		token := c.Request.Header.Get("Authorization")
				authorized := check(token)
				if authorized {
					c.Next()
					return
				}
				c.JSON(http.StatusUnauthorized, gin.H{
					"error": "Unauthorized",
				})
				c.Abort()*/
		return
	}
}

func loginMemory(w http.ResponseWriter, r *http.Request) {
	fmt.Println("method: ", r.Method)
	if r.Method == "GET" {
		t, _ := template.ParseFiles("login.tpl")
		log.Println(t.Execute(w, nil))
	} else {
		_ = r.ParseForm()
		fmt.Println("username: ", r.Form["username"])
		fmt.Println("password: ", r.Form["password"])
		user1 := User{1, r.Form.Get("username"), r.Form.Get("password"), "0"}
		store(user1)

		if r.Form.Get("password") == "123456" {
			fmt.Fprintf(w, "欢迎登陆,Hello %s", r.Form.Get("username"))
		} else {
			fmt.Println(w, "密码错误，重新输入")
		}
	}
}

func store(user User) {
	/*//内存存储
	UserById[user.Id] = &user
	UserByName[user.Name] = append(UserByName[user.Name], &user)*/

	//MySQL存储
	stmt, _ := db.Prepare("INSERT INTO users SET NAME=?,HABITS=?,CREATETIME=?")
	t := time.Now().UTC().Format("2022-01-01")
	stmt.Exec(user.Name, user.Password, t)

}

func userInfo(w http.ResponseWriter, r *http.Request) {
	/*	//内存查询
		fmt.Println(UserById[1])
		r.ParseForm()
		for _, user := range UserByName[r.Form.Get("username")] {
			fmt.Fprintf(w, "%v", user)
		}*/

	//MySQL查询
	_ = r.ParseForm()
	if r.Method == "POST" {
		user1 := User{Name: r.Form.Get("username"), Password: r.Form.Get("password")}
		store(user1)
		fmt.Println(w, "%v", queryByName(r.Form.Get("username")))
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

func queryByName(name string) User {
	user := User{}
	stmt, _ := db.Prepare("select * from users where NAME=?")
	rows, _ := stmt.Query(name)
	fmt.Println("\nafter deleting records: ")

	for rows.Next() {
		var id int
		var name string
		var habits string
		var createTime string
		err = rows.Scan(&id, &name, &habits, &createTime)

		fmt.Printf("{%d,%s,%s,%s}\n", id, name, habits, createTime)
		user = User{id, name, habits, createTime}
		break
	}

	return user
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
