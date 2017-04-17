import java.net.*;

public class Cliente{
  public static void main(String[] args) {
    String cadena = args[1];
    System.out.println(cadena);
    try{
      InetAddress host = InetAddress.getByName(args[0]);
      int pto = 7200;
      DatagramSocket dataSocket = new DatagramSocket();
      byte[] datos = cadena.getBytes();
      byte[] buffer = new byte[1024];
      DatagramPacket dataPacket = new DatagramPacket(datos, datos.length, host, pto);
      DatagramPacket dPack = new DatagramPacket(buffer, buffer.length, host, pto);
      dataSocket.send(dataPacket);
      while(true){
        dataSocket.receive(dPack);
        byte[] data = dPack.getData();
        String msg1 = new String(data, 0, 5);
        System.out.println("Here is SOME :" + msg1);
        dPack.setLength(buffer.length);


      }
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
