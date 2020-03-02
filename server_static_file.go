package main

import(
    "log"
    "net/http"
)

func sendContentFile(w http.ResponseWriter, r *http.Request) {
    http.ServeFile(w, r, r.URL.Path[1:]);
}

func main() {
    http.HandleFunc("/", sendContentFile);
    log.Fatal(http.ListenAndServe(":8083", nil))
}
