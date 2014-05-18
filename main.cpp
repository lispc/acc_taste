#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct Trie_node{
	Trie_node(){
		c = 0;
		memset(kv,0,sizeof(kv));
	}
	char c;
	Trie_node* kv[256];
	vector<int> ids;
}
Trie_node root;
void insert_trie(string s,int id){
	int l = s.size();
	Trie_node* cur = &root; 
	for(int i=0;i<l;i++){
		char c = s[i];
		unsigned int ci = (unsigned char)c;
		if(cur->kv[ci]==NULL){
			cur->kv[ci] = new Trie_node;
			cur->kv[ci]->c = c;
		}
		cur = cur->kv[ci];
	}
	if(cur->ids[cur->ids.size()-1]!=id)
		cur->ids.push_back(id);
}
/*
void dump_trie_rec(int indent, Trie_node* p){
	for(int i=0;i<indent;i++)
		cerr<<" ";
	
void dump_trie(){
	dump_trie_rec(0,&root);
}
*/
void init_buf(){
	for(int i=0;i<200;i++){
		buf[0][i]=i;
		buf[i][0]=i;
	}
}
vector<pair<int,int> > ed_get(string pattern, string text){
	vector<pair<int,int> > res;
	int tao = 2;
	int pl = pattern.size();
	int tl = text.size();
	if(pl==0){
		for(int i=0;i<=tao;i++)
			res.push_back(pair(i,i));
		return res;
	}
	for(int j=1;j<=pl;i++){
		int st = max(j-tao+1,0);
		int ed = min(tl,j+tao-1);
		if(j-tao>=1)
			buf[j-tao][j]=tao;
		for(int i=st;i<=ed;i++){
			if(pattern[j]==text[i])
				buf[i][j]=buf[i-1][j-1];
			else{
				buf[i][j]=min(buf[i-1][j-1]+1,min(buf[i-1][j]+1,buf[i][j-1]+1));
			}
		}
		if(ed<tl)
			buf[ed+1][j]=tao;
		bool b = true;
		for(int i=st;i<ed;i++){
			if(buf[i][j]<=tao){
				b = false;
				break;
			}
		}
		if(b)
			return res;
	}
	for(int i=max(0,j-tao+1);i<=min(tl,j+tao-1);i++){
		if(buf[i][pl]<=tao)
			res.push_back(pair(i,buf[i][pl]));
	}
	return res;
}
int buf[200][200];
vector<string> es;
int main(int argc,char** argv){
	if(argc!=3){
		puts("exe doc entity")
		exit(-1);
	}
	string doc_fname = argv[1];
	string entity_fname = argv[2];
	ifstream doc_fs(doc_fname);
	ifstream entity_fs(entity_fname);
	string e;
	int tao = 2;
	int line_id = 0;
	int min_len = 19920211;
	int max_len = -19941204;
	while(entity_fs>>e){
		es.push_back(es);
		int l = e.size();//3 3 2
		if(l<min_len)
			min_len = l;
		if(l>max_len)
			max_len = l;
		int lb = l/(tao+1);//8/3=2
		int long_num = l-lb*(tao+1);//2=8-2*3
		int start_pos = 0;
		for(int i=0;i<tao+1;i++){
			int len;
			if(i<long_num){
				len = lb+1;
			}else{
				len = lb;
			}
			string seg = e.substr(start_pos,len);
			insert_trie(seg,line_id);
			start_pos += len;
		}
		line_id += 1;
	}
	string d;
	int doc_id = 0;
	while(doc_fs>>d){
		int l = d.size();
		if(l>max_len+tao||l<min_len-tao){
			doc_id += 1;
			continue;
		}
		vector<int> candidates;
		for(int i=0;i<l;i++){
			int start_pos = i;
			Trie_node* cur = &root;
			for(int j=i;j<l;j++){
				if(cur->ids.size()!=0){
					for(int k=0;k<cur->ids.size();k++){
						 string can = es[cur->ids[k]];
						 string tp_seg = d.substr(i,j);
						 int loc;
						 while((loc=can.find(tp_seg))!=-1){
							 string left = can.substr(0,loc);
							 string right = can.substr(loc+tp_seg.size());


				}
				char c = d[j];
				unsigned int ci = (unsigned char)c;
				if(cur->kv[ci]==NULL)
					break;
				else{
					cur = cur->kv[ci];
				}
			}
				
