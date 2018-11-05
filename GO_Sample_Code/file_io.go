package main

import (
  "bufio"
  "fmt"
  "io/ioutil"
  "os"
)

func check_error(e error){
    if e != nil{
      panic(e)
    }
}

func sum_int(a int64, b int64) (int64, int64) {
    fmt.Println("Done")
    return a, b
}

type blockchain_addr struct{
    addr_index int64
    addr_store_cache string
}

type blockchain_methods interface{
    getAddr() string
    getIndex() int64
}

func(addr blockchain_addr) getAddr() string {
    return addr.addr_store_cache
}

func(addr blockchain_addr) getIndex() int64 {
    return addr.addr_index
}

func get_block_info(bitfunc blockchain_methods){
    fmt.Println(bitfunc)
    fmt.Println(bitfunc.getAddr())
    fmt.Println(bitfunc. getIndex())
}

func main() {
    s := make([]string, 4)
    bitcoin_addr := blockchain_addr{addr_index : 85, addr_store_cache : "bitcoin"}

    s[0] = "a"
    s[1] = "ed"
    s[2] = "rf"
    s[3] = "weert"
    l := s[:3]
    v := s[2:]
    b := s[1:3]
    matrix_array := make([][]int64, 3)
    fmt.Println(l)
    fmt.Println(v)
    fmt.Println(b)
    fmt.Println(s[3])
    for i := 0; i < 3; i++ {
      innnerLen := i + 1
      matrix_array[i] = make([]int64, innnerLen)
      for j := 0; j < innnerLen; j++ {
        matrix_array[i][j] = 0x01548965abcfe45d7
      }
    }

    fmt.Println(matrix_array)
    map_key_value := make(map[string]string)
    map_key_value["Sumit"] = "Lahiri"
    map_key_value["John"] = "Cena"
    v1, prs := map_key_value["Sumit"]
    v2, sed := map_key_value["Upool"]
    fmt.Println("Present : ", prs, "Value : ", v1)
    fmt.Println("Present : ", sed, "Value : ", v2)

    for k, v := range map_key_value{
      fmt.Println(k, v)
    }

    func(msg string){
      fmt.Println(msg)
    }("Anonymous Function Call")

    sum_int(745058774, 634574504)
    fmt.Println("done")

    PrintNum := func(a int64) {
      fmt.Println(a)
    }

    var age int64
    PrintNum(3)
    fmt.Println("Enter a number")
     _, err := fmt.Scan(&age)

    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter text: ")
    text, op := reader.ReadString('\n')
    fmt.Println(text, op)

    get_block_info(bitcoin_addr)

    fmt.Println(age, err)

    file_create, err := os.Create("/tmp/heaven.dat")
    check_error(err)
    defer file_create.Close()

    data_bytes := []byte("jmnosadnfnjnounsd\nsodnfnounasoundgf\niusdfiuunsdunfgojnasdoughf\niusangiiohgojasndgfnojsngjnubojnasfugjnafsughoununuanfsdoughnoashghuhfgonurgwhjg24uoing80rngn098n4308gnwiong08N2W4GN09RNG0NASOIGVN09N\n")
    file := ioutil.WriteFile("/tmp/heaven.dat", data_bytes, 0644)
    check_error(file)

    file2_create, err := os.Create("/tmp/heaven2.dat")
    check_error(err)
    defer file2_create.Close()

    bytes, err := file2_create.Write(data_bytes)
    fmt.Println(bytes, err)

    string_write, err := file_create.WriteString("Hello There\n")
    fmt.Println(string_write, err)
    check_error(err)

    log_file, err := os.OpenFile("log.fmllog", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
    check_error(err)
    defer log_file.Close()

    raw_dat, err := log_file.Write(data_bytes[:5])
    check_error(err)
    fmt.Println("LOG : ", raw_dat, err)

    raw_string, err := log_file.WriteString("\nThis is a twoD matrix\n")
    fmt.Println("LOG : ", raw_string, err)
    check_error(err)

    dat, err := ioutil.ReadFile("log.fmllog")
    check_error(err)
    fmt.Println(string(dat))

    fmt.Scanln()
    d, err_w := log_file.WriteString("\nThis is a twoD matrix\n")
    log, err := os.Open("log.fmllog")
    byte_block := make([]byte, 18)
    rawdata, err := log.Read(byte_block)
    check_error(err_w)
    fmt.Printf("%d bytes : %s\n", rawdata, string(byte_block), d)

    log.Close()
}
