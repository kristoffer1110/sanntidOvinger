// Use `go run foo.go` to run your program

package main

import (
	. "fmt"
	"runtime"
	//"time"
)

var i = 0

func incrementing(incCh chan int) {
    //TODO: increment i 1000000 times
    for n := 0; n < 8; n++ {
        incCh <- 1
    }
    close(incCh)
}

func decrementing(decCh chan int) {
    //TODO: decrement i 1000000 times
    for m := 0; m < 10; m++ {
        decCh <- 1
    }
    close(decCh)
}

func server(incCh, decCh chan int){
    var quit = 0
    for{
        select{
        case inc, okInc := <- incCh:
            if inc == 1{
                i++
            } 
            if okInc == false{
                quit++
            }
        case dec, okDec := <- decCh:
            if dec == 1{
                i--
            }
            if okDec == false{
                quit++
            }
        }
        print(quit)
        if quit == 2{
            break
        }
    }
}   

func main() {
    // What does GOMAXPROCS do? What happens if you set it to 1?
    runtime.GOMAXPROCS(2)
    
    // GOMAXPROCS specifies how many threads or processes that can run simultaneously. If we set it to one, we will only execute one thread at a time, reducing efficiency

    incCh := make(chan int)
    decCh := make(chan int)


    // TODO: Spawn both functions as goroutines
    go incrementing(incCh)
    go decrementing(decCh)
    go server(incCh, decCh)

    

	
    // We have no direct way to wait for the completion of a goroutine (without additional synchronization of some sort)
    // We will do it properly with channels soon. For now: Sleep.
    //time.Sleep(500*time.Millisecond)
    Println("The magic number is: ", i)
}
