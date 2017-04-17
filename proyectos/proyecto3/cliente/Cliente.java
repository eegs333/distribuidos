import java.net.*;

public class Cliente{
  public static void main(String[] args) {
    String cadena = args[1];
    System.out.println(cadena);
    try{
      InetAddress host = InetAddress.getByName(args[0]);
      int pto = 7200;
      DatagramSocket dataSocket = new DatagramSocket();
  //    while(true){
        byte[] datos = cadena.getBytes();
        DatagramPacket dataPacket = new DatagramPacket(datos, datos.length, host, pto);
        dataSocket.send(dataPacket);
//      }
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
