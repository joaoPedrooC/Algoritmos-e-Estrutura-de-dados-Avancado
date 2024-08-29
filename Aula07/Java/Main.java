import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Arvore arvore = new Arvore();
    Scanner scanner = new Scanner(System.in);

    while (true) {
      int opcao;

      System.out.println("1. Inserir\n2. Procurar\n");
      opcao = scanner.nextInt();

      if (opcao == -1) {
        break;
      } else if (opcao == 1) {
        int valor;
        
        System.out.println("Digite o valor para inserir: ");
        valor = scanner.nextInt();

        arvore.InserirNovoNo(valor);
      } else if (opcao == 2) {
        int valor;
        valor = scanner.nextInt();

        System.out.println("Resultado: " + arvore.ProcurarValor(valor));
      }
    }

    scanner.close();
  }
}
