package main

import (
  "fmt"
	"bufio"
	"io"
	"io/ioutil"
	"log"
	"os"
	"strings"
)

const logfile = "error_log.log"

func check_error(err error) {
    if err != nil {
      log.Fatalf("Uncaught Error: %v", err)
  }
}

func WriteDumpFileLines(filename string, run int) {
    dump_string := "Writing to dump file.\n"
    file_os, err := os.OpenFile(filename, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
    check_error(err)
    for i := 0; i < run; i++ {
        _, err := file_os.WriteString(dump_string)
        check_error(err)
    }
    file_os.Close()
}

func ReadDumpFileLines(filename string) []string {
    dump_string := make([]string, 1)
    file_os, err := os.OpenFile(filename, os.O_RDONLY, os.ModePerm)
    check_error(err)
    reader := bufio.NewReader(file_os)
    for {
      line, err := reader.ReadString('\n')
      if err != nil {
        if err == io.EOF {
          break
        }
        log.Fatalf("Read file line error. %v", err)
      }
      dump_string = append(dump_string, line)
    }
    file_os.Close()
    return dump_string
}

func main() {
    filename := "/tmp/dump.dat"
    WriteDumpFileLines(filename, 10000000)
    dump_array := ReadDumpFileLines(filename)
    data, err := ioutil.ReadFile(logfile)
    check_error(err)
    ss := strings.Split(string(data), "\n")
    for z, s := range ss {
      fmt.Println(z, s)
    }
    fmt.Println(dump_array)
}
