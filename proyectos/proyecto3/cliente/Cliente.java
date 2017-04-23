import java.net.*;
import java.nio.*;

public class Cliente{
  public static void main(String[] args) {
    String ip = args[0];
    String cadena = args[1];
    String offset;

    System.out.println(cadena);
    try{
      InetAddress host = InetAddress.getByName(ip);
      int pto = 7200;
      DatagramSocket dataSocket = new DatagramSocket();
      byte[] datos = cadena.getBytes();
      byte[] buffer = new byte[1024];
      DatagramPacket dataPacket = new DatagramPacket(datos, datos.length, host, pto);
      DatagramPacket dPack = new DatagramPacket(buffer, buffer.length, host, pto);
      dataSocket.send(dataPacket);
      while(true){
        dataSocket.receive(dPack);
      //  byte[] data = dPack.getData();
        //String msg1 = dPack.getData();
      //  String msg1 = new String(data, 0, 64);
      //  System.out.println("Here is SOME :" + msg1);
        //dPack.setLength(buffer.length);
        ByteBuffer bb = ByteBuffer.wrap(dPack.getData());
        bb.order(ByteOrder.LITTLE_ENDIAN);
        StringBuilder sb = new StringBuilder();
        byte nameByte;
        while ( (nameByte = bb.get()) != '\0' )
          sb.append((char) nameByte);
        System.out.println("Here is SOME :" + sb.toString());
        StringBuilder sb2 = new StringBuilder();
        byte nameByte2;
        while ( (nameByte2 = bb.get()) != '\0' )
          sb2.append((char) nameByte2);
        System.out.println("Here is SOME2 :" + sb2.toString());
      }
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
