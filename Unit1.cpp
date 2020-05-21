//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Tree.h"
#include "MyTask6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow,
		  bool &CanSelect)
{
	CanSelect = false;
}

//��� �������� �����
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "�.�.�.";
	StringGrid1->Cells[1][0]="����";
	StringGrid1->Cells[0][1]="������ �.�."; StringGrid1->Cells[1][1]="7";
	StringGrid1->Cells[0][2]="������� �.�."; StringGrid1->Cells[1][2]="2";
	StringGrid1->Cells[0][3]="����� �.�."; StringGrid1->Cells[1][3]="6";
	StringGrid1->Cells[0][4]="������ �.�."; StringGrid1->Cells[1][4]="9";
	StringGrid1->Cells[0][5]="��������� �.�."; StringGrid1->Cells[1][5]="5";
	StringGrid1->Cells[0][6]="����������� �.�."; StringGrid1->Cells[1][6]="12";
	StringGrid1->Cells[0][7]="������ �.�."; StringGrid1->Cells[1][7]="4";
	StringGrid1->Cells[0][8]="������ �.�."; StringGrid1->Cells[1][8]="8";
	StringGrid1->Cells[0][9]="���������� �.�."; StringGrid1->Cells[1][9]="10";
	StringGrid1->Cells[0][10]="�������� �.�."; StringGrid1->Cells[1][10]="1";
}

Tree *tree;
TTree *root;

//������ "������� (�� �������)"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	TreeView1->Items->Clear();
	Memo1->Clear();
	tree->AddArrayToTree(&root, StringGrid1);
}

//������ "��������������"
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else
	{
        TreeView1->Items->Clear();
		Memo1->Clear();
		int size = tree->ListCount(root);
		TInf *array = new TInf[size];
		tree->ReturnBallanced(&root, size, array);
		delete[] array;
        tree->ViewTree(root, -1, TreeView1);
		TreeView1->FullExpand();
	}

}

//������ "��������"
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	AnsiString str = Edit2->Text;
	if (Edit1->Text == "" || str == "")
	{
		Application->Title = "������";
		ShowMessage("������� ������ ��� ����������!");
	}
	else if(str[1] == ' ')
	{
		Edit2->Text = "";
        Application->Title = "������";
		ShowMessage("������� ������ ��� ����������!");
    }
	else
	{
		TInf inf;
		inf.key = StrToInt(Edit1->Text);
		inf.fio = Edit2->Text;
		tree->AddList(&root, inf);
		Edit1->Text = "";
		Edit2->Text = "";
        TreeView1->Items->Clear();
		Memo1->Clear();
	}
}

//������ "������� (�� �����)"
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else if(Edit1->Text == "")
	{
		Application->Title = "������";
		ShowMessage("������� ���� ��� ��������!");
	}
	else
	{
		root = tree->DelInfo(root, StrToInt(Edit1->Text));
		Edit1->Text = "";
		TreeView1->Items->Clear();
		Memo1->Clear();
	}
}

//������ "����� (�� �����)"
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else if(Edit1->Text == "")
	{
		Application->Title = "������";
		ShowMessage("������� ���� ��� ������!");
	}
	else
	{
		TreeView1->Items->Clear();
		Memo1->Clear();
		tree->SearchInfo(root, StrToInt(Edit1->Text), Memo1);
        Edit1->Text = "";
	}
}

//������ "� TreeView"
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else
	{
		TreeView1->Items->Clear();
		Memo1->Clear();
		tree->ViewTree(root, -1, TreeView1);
		TreeView1->FullExpand();
	}
}

//������ "������ �����"
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else
	{
		Memo1->Clear();
		tree->PrPrintTree(&root, Memo1);
	}
}

//������ "�������� �����"
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else
	{
		Memo1->Clear();
		tree->ObPrintTree(&root, Memo1);
	}
}

//������ "������������ �����"
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else
	{
		Memo1->Clear();
		tree->SimPrintTree(&root, Memo1);
	}
}

//������ "���� �������"
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    if(root == NULL)
	{
		Application->Title = "��������";
		ShowMessage("� ������ ��� ���������!");
	}
	else
	{
		Application->Title = "�������";
		ShowMessage("6. ������� �� ����� ����� ������ ���� � ������������"
			" ��������� ����� � ��� ��������� � ��� ����."
			"\n\n������ ������� ����� �������� ������:"
			"\n1. ������� ������� ��������� � \"������\" � max ����;"
			"\n2. ������� ������ ��������������� \"��������� � ��� ����\" - ������"
			" ������ ����� (�.�. ���� � ���� ���� ������, �� �� �� ������������)."
			"\n\n������ ������ ��������� 1 ������� (2 ������� ��������� ���������"
			"�������� ���������� �� �������� ������� � ��� �� ������ MyTask)");
		TreeView1->Items->Clear();
		Memo1->Clear();
		MyTask *myTask;
		myTask->DeleteMaxLeftWithConnected(&root, Memo1);
		tree->ViewTree(root, -1, TreeView1);
		TreeView1->FullExpand();
	}
}

//������ "�����"
void __fastcall TForm1::Button11Click(TObject *Sender)
{
	tree->DeleteTree(&root);
	Memo1->Clear();
	TreeView1->Items->Clear();
	Close();
}

