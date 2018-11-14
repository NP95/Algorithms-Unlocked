package main

import "fmt"
import "strings"
import "time"

var global_queue = make(chan string, 700)

func WriteString(str string) string {
    splits := strings.Split(str, "\n")
    for term, CONTENT := range splits {
      fmt.Println(term, " : ", CONTENT)
      global_queue <- CONTENT
    }
    return splits[2]
}

func worker_pool(nums int) {
    for i:= 0; i < nums; i++ {
      go WriteString("Hello\nlldljnksnjnf\njonsdfnun\n")
    }
}

func worker(id int, jobs <-chan int, results chan<- int)  {
    for j := range jobs {
      fmt.Println("worker", id, "started job now.", j)
      time.Sleep(time.Second)
      fmt.Println("worker", id, "finished job now", j)
      results <- j * 4
    }
}

const conc_str = "GOLANGGO\ncdHelloThere\nddfHi\nLiddfne\nOsdfKAU\npfasdflc\nijyDFB"
const str = "SDFFSADFGOLANGGO\nHello-There\nHi\nLine\nOKAU\nplc"

func main() {
    WriteString(str)
    go WriteString(conc_str)
    defer WriteString(str + conc_str)

    messege_queue := make(chan string, 3)
    messege_queue <- WriteString(str)
    messege_queue <- WriteString(conc_str)
    messege_queue <- WriteString(str[:3] + conc_str[4:])
    fmt.Println(<-messege_queue)
    fmt.Println(<-messege_queue)
    fmt.Println(<-messege_queue)

    jobs := make(chan int, 100)
    results := make(chan int, 100)

    // How many workers do we want to start
    for i := 0; i <= 30; i++ {
        go worker(i, jobs, results)
    }

    // Now we put jobs
    for i := 0; i <= 50; i++ {
        jobs <- i
    }

    // No more jobs
    close(jobs)

    for j := range results {
        k := <- results
        fmt.Println(k, j)
    }
    // Deadlock Example
    // <- global_queue
}
