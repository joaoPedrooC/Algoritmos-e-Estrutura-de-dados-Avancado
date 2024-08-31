import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    Arvore arv = new Arvore();

    while (true) {
      int opcao;

      System.out.println("\n1.Inserir\n2.Busca\n3.Imprimir O. Crescente\n4.Imprimir O. Decrescente\n5.Contar Elementos\n6.Somar Elementos\n7.Encontrar Menor\n8.Encontrar Maior\n9.Imprimir Folhas\n10.Imprimir Nao Folhas\n11.Remover:\n");
      opcao = scanner.nextInt();

      if(opcao == 1) {
        int valor;
        valor = scanner.nextInt();

        arv.InserirNo(valor);
      } else if(opcao == 2) {
        int valor = scanner.nextInt();
        boolean resultado = arv.Buscar(valor);

        System.out.println("Resultado: " + resultado);
      } else if(opcao == 3) {
        arv.ImprimirCrescente(arv.raiz);
      } else if(opcao == 4) {
        arv.ImprimirDecrescente(arv.raiz);
      } else if(opcao == 5) {
        int resultado = arv.ContarElementos(arv.raiz);
        System.out.println("Resultado: " + resultado);
      } else if(opcao == 6) {
        int resultado = arv.SomarElementos(arv.raiz);
        System.out.println("Resultado: " + resultado);
      } else if(opcao == 7) {
        int resultado = arv.ProcurarMenorElemento(arv.raiz);
        System.out.println("Menor: " + resultado);
      } else if(opcao == 8) {
        int resultado = arv.ProcurarMaiorElemento(arv.raiz);
        System.out.println("Maior: " + resultado);
      } else if(opcao == 9) {
        arv.ImprimirFolhas(arv.raiz);
      } else if(opcao == 10) {
        arv.ImprimirNaoFolhas(arv.raiz);
      } else if(opcao == 11) {
        int valor = scanner.nextInt();

        arv.RemoverNo(valor);
        arv.ImprimirCrescente(arv.raiz);
      } else {
        System.out.println("Entrada invalida.\n");
      }
    }
  }
}
