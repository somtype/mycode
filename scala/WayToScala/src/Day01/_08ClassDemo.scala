package Day01

object _08ClassDemo {
  class Customer(var name:String = "", var address:String = ""){
    def this(args:Array[String]){
      this(args(0), args(1))
    }
  }

  def main(args: Array[String]): Unit = {
    var customer = new Customer(Array[String]("范雨茹", "福建"))
    println(customer.name)
    println(customer.address)
  }
}
