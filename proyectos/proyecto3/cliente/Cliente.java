import java.net.*;
import java.nio.*;
import java.io.*;
import java.util.Arrays;
import java.io.InputStreamReader;

public class Cliente{

  public static void main(String[] args) {

    String ip = args[0];
    String cadena = args[1];
  //  String offset;
    int BYTES_PER_CHARARACTER = Character.SIZE / 8;
    int BYTES_FOR_LENGTH = 2;
    //String handle;
    int offset = 0;

    try{
      InetAddress host = InetAddress.getByName(ip);
      int pto = 7200;
      DatagramSocket dataSocket = new DatagramSocket();
      byte[] datos = cadena.getBytes();
      byte[] buffer = new byte[64];
      DatagramPacket sendData = new DatagramPacket(datos, datos.length, host, pto);
      DatagramPacket receiveData = new DatagramPacket(buffer, buffer.length, host, pto);
      dataSocket.send(sendData);

      while(true){
        dataSocket.receive(receiveData);
        byte[] bytes = receiveData.getData();
        String msg2 = new String(bytes,30,32);
        ByteBuffer buf = ByteBuffer.wrap(receiveData.getData());
        ByteBuffer buf2 = buf.slice();
        buf.order(ByteOrder.LITTLE_ENDIAN);
        StringBuilder sb = new StringBuilder();
        byte nameByte;
        while ( (nameByte = buf.get()) != '\0' )
          sb.append((char) nameByte);
        System.out.println(sb.toString());

      //  buf.flip();
        //ByteBuffer bb = ByteBuffer.wrap(bytes);
        //byte[] b = new byte[buf.remaining()];
      //  buf.get(b);

        System.out.println(msg2);
      //  System.out.println((char)buf.get());

      }
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
