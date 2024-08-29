public class Arvore {
  public No raiz;

  public void InserirNovoNo(int valor) {
    if (this.raiz == null) {
      No novoNo = new No();

      novoNo.valor = valor;
      novoNo.no_direita = null;
      novoNo.no_esquerda = null;
      
      this.raiz = novoNo;
    }

    No copiaRaiz = this.raiz;
    No ponto_insercao = this.raiz;

    while(copiaRaiz != null) {
      ponto_insercao = copiaRaiz;

      if (copiaRaiz.valor < valor) {
        copiaRaiz = copiaRaiz.no_direita;
      } else {
        copiaRaiz = copiaRaiz.no_esquerda;
      }
    }

    No novoNo = new No();

    novoNo.valor = valor;
    novoNo.no_direita = null;
    novoNo.no_esquerda = null;
    
    if (ponto_insercao.valor < valor) {
      ponto_insercao.no_direita = novoNo;
    } else {
      ponto_insercao.no_esquerda = novoNo;
    }
  }

  public boolean ProcurarValor(int valor) {
    No copiaRaiz = this.raiz;

    while (copiaRaiz != null) {
      if(copiaRaiz.valor == valor) return true;
      else if(copiaRaiz.valor < valor) {
        copiaRaiz = copiaRaiz.no_direita;
      } else {
        copiaRaiz = copiaRaiz.no_esquerda;
      }
    }

    return false;
  }
}
