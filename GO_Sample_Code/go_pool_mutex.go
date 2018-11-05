package main

import (
  "fmt"
  "math/rand"
  "sync"
  "sync/atomic"
  "strings"
  "time"
)

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

  // For our example the `state` will be a map.
  var state = make(map[int]int)

  // This `mutex` will synchronize access to `state`.
  var mutex = &sync.Mutex{}

  // We'll keep track of how many read and write
  // operations we do.
  var readOps uint64
  var writeOps uint64

  // Here we start 100 goroutines to execute repeated
  // reads against the state, once per millisecond in
  // each goroutine.
  for r := 0; r < 100; r++ {
      go func() {
          total := 0
          for {

              // For each read we pick a key to access,
              // `Lock()` the `mutex` to ensure
              // exclusive access to the `state`, read
              // the value at the chosen key,
              // `Unlock()` the mutex, and increment
              // the `readOps` count.
              key := rand.Intn(5)
              mutex.Lock()
              total += state[key]
              mutex.Unlock()
              atomic.AddUint64(&readOps, 1)

              // Wait a bit between reads.
              time.Sleep(time.Millisecond)
          }
      }()
  }

  // We'll also start 10 goroutines to simulate writes,
  // using the same pattern we did for reads.
  for w := 0; w < 10; w++ {
      go func() {
          for {
              key := rand.Intn(5)
              val := rand.Intn(100)
              mutex.Lock()
              state[key] = val
              mutex.Unlock()
              atomic.AddUint64(&writeOps, 1)
              time.Sleep(time.Millisecond)
          }
      }()
  }

  // Let the 10 goroutines work on the `state` and
  // `mutex` for a second.
  time.Sleep(time.Second)

  // Take and report final operation counts.
  readOpsFinal := atomic.LoadUint64(&readOps)
  fmt.Println("readOps:", readOpsFinal)
  writeOpsFinal := atomic.LoadUint64(&writeOps)
  fmt.Println("writeOps:", writeOpsFinal)

  // With a final lock of `state`, show how it ended up.
  mutex.Lock()
  fmt.Println("state:", state)
  mutex.Unlock()



    WriteString(str)
    go WriteString(conc_str)
    defer WriteString(str + conc_str)

    time.Sleep(time.Second)

    messege_queue := make(chan string, 3)

    messege_queue <- WriteString(str)
    messege_queue <- WriteString(conc_str)
    messege_queue <- WriteString(str[:3] + conc_str[4:])

    fmt.Println(<-messege_queue)
    fmt.Println(<-messege_queue)
    fmt.Println(<-messege_queue)

    time.Sleep(time.Second)

    jobs := make(chan int, 100)
    results := make(chan int, 100)

    time.Sleep(time.Second)

    // How many workers do we want to start
    for i := 0; i <= 300; i++ {
        go worker(i, jobs, results)
    }

    // Now we put jobs
    for i := 0; i <= 100; i++ {
        jobs <- i
    }

    // No more jobs
    close(jobs)
    time.Sleep(time.Second)
    <- results

    var ops uint64
    for i := 0; i < 512; i++ {
        go func() {
          for {
            atomic.AddUint64(&ops, 1)
            time.Sleep(time.Millisecond)
          }
        }()
    }
    time.Sleep(time.Second)

    opsFinal := atomic.LoadUint64(&ops)

    fmt.Println("ops : ", opsFinal)
    // Deadlock Example
    // <- global_queue
}
